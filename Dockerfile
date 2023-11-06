FROM php:7.2

RUN apt-get update && apt-get install -y g++ git

RUN apt-get update && apt-get install -y bash

WORKDIR /php-cpp
RUN git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git .
RUN make
RUN make install

RUN apt-get clean

WORKDIR /var/www/html

COPY index.php /var/www/html/index.php
COPY hello_world_extension.cpp /php-cpp/hello_world_extension.cpp
#-fPIC possition independent compiling
RUN g++ -shared -o /php-cpp/hello_world_extension.so -fPIC /php-cpp/hello_world_extension.cpp -I/usr/include/php/20170718/ -I/usr/include/php/20170718/main -I/usr/include/php/20170718/TSRM -I/usr/include/php/20170718/Zend -I/usr/include/php/20170718/ext -lphpcpp

RUN mv /php-cpp/hello_world_extension.so /usr/local/lib/php/extensions/no-debug-non-zts-20170718/ && echo "extension=hello_world_extension.so" > /usr/local/etc/php/conf.d/hello_world_extension.ini

EXPOSE 80

CMD ["php", "-S", "0.0.0.0:80", "-t", "/var/www/html"]