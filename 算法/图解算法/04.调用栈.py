def greet2(name):
	print("how are you," + name + "?")
	
def bye():
	print("bye!")
	
def greet(name):
	greet2(name)
	bye()

# None ==> greet ==> greet->greet2 ==> greet ==> greet->bye ==> greet ==> None
#   greet入栈   greet2入栈      greet2出栈    bye入栈        bye出栈    greet出栈
greet("tom")