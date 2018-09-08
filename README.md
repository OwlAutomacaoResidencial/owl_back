# owl_back

Owl Project backend. <br>
Run on Raspberry PI 3. <br>
Developed on Jessie Debian. <br>

# Dependencies

 - Boost 1.55.0
 - MySQL Connector/C++
 - RapidJson
 - Crow

# How to install dependencies

#  Boost

wget -O boost_1_55_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.55.0/boost_1_55_0.tar.gz/download <br>
tar xzvf boost_1_55_0.tar.gz <br>
cd boost_1_55_0/

<h3> To download boost dependencies : </h3>
sudo apt-get update <br>
sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev build-essential libbz2-dev libboost-all-dev <br>

<h3> Boost boostrap setup </h3>

./bootstrap.sh --prefix=/usr/ <br>

<h3> Then build it with: <h3>

./b2 <br>

<h3> and eventually install it: </h3>

sudo ./b2 install <br>
