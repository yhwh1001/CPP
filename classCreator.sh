#!/bin/bash

#check if nbr of arguments not equal to 1 or zero lemght string
#[ $# -ne 1 ] ||
if [ -z "$1" ]; then
    echo "Usage: ./create_class.sh ClassName"
    exit 1
fi

CLASS=$1
UPPER=$(echo "$CLASS" | tr '[:lower:]' '[:upper:]')
DATE=$(date +"%Y/%m/%d %H:%M:%S")
HPP_NAME=$(printf "%-51s" "${CLASS}.hpp")
CPP_NAME=$(printf "%-51s" "${CLASS}.cpp")

#create .hpp file
cat > "${CLASS}.hpp" << EOF
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${HPP_NAME}:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${DATE} by mcarvalh          #+#    #+#             */
/*   Updated: ${DATE} by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ${UPPER}_HPP
#define ${UPPER}_HPP

#include <iostream>

class ${CLASS} {
	public:
			${CLASS}();
			${CLASS}(const ${CLASS}& other);
			${CLASS}& operator=(const ${CLASS}& other);
			~${CLASS}();
	
	private:

};

#endif
EOF

#Create a .cpp file
cat > "${CLASS}.cpp" << EOF
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${CPP_NAME}:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${DATE} by mcarvalh          #+#    #+#             */
/*   Updated: ${DATE} by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "${CLASS}.hpp"

${CLASS}::${CLASS}() {}

${CLASS}::${CLASS}(const ${CLASS}& other) {
	*this = other;
}

${CLASS}& ${CLASS}::operator=(const ${CLASS}& other) {
	if (this != &other){
		//copy attributes
	}
	return *this;
}

${CLASS}::~${CLASS}() {}

EOF

echo "Successfully created ${CLASS}.hpp and ${CLASS}.cpp :)"