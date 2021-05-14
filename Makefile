all: depencies

depencies:
	sudo apt-get install nasm -y
	sudo apt-get install gcc -y
	sudo apt-get install g++ -y
	sudo apt-get install mkisofs -y