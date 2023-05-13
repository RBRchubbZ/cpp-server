# cpp-server
## Install Crow --Linux--
### Step 1 -- Download Crow
Use `wget` to retrieve the `.deb` file  
> `wget https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow-v1.0+5.deb`

### Step 2 -- Install Crow
Use `dpkg` to install the `.deb` file  
> `sudo dpkg -i crow-v1.0+5.deb`

### Step 3 -- may not need
From linux go into `/usr/include`
> use `wget https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow_all.h`
> > if premission is denied use: `sudo`

### Step 4 -- Download Boost
Download the Boost package
> use `apt install libboost-dev`
> > Full library is not needed So dont do `-all`

### Step 4 -- Copy/Write mini server
1. Download the server.cpp file
2. Compile the file
  > use `g++ server.cpp -o server -lpthread`
  > > `-o` will allow you to name the compiled file
3. Run the compiled file 
 > `./server`

### Step 5 -- Check Connection
You should now be able to access `localhost:8000`


### FUTURE STEPS HERE
