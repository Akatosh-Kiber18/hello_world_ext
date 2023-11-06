Build container

``` 
docker build -t php-cpp-container .
```

Run container

```
docker run -p 8080:80 php-cpp-container
```

Enter into container
```
docker exec -it [container ID] /bin/bash
```
Now you can contemplate the art by executing
```
php index.php
```
