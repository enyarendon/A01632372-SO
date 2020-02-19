compila:
	gcc hello.c -o hello #Compila
	./hello  			#Ejecuta
clean: 
	rm hello
push:
	git add .
	git commit -m "message"
	git push origin master