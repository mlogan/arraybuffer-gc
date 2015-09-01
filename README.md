# To reproduce:

	nvm install iojs-3.2.0
	nvm use iojs-3.2.0

	which npm # verify that this is from the iojs-3.2.0 directory
	npm install -g pangyp
	pangyp configure build

	which node # verify that this is from the iojs-3.2.0 directory
	node --trace-gc test.js
