

class Node:
    def __init__(self,data):
        self.data = data
        self.prev = None
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = Node(None)

    def push(self,data):
        newNode = Node(data)
        last = self.head
    
        if(self.head is None):
        	self.head = newNode


        else:
        	while(last.next is not None):
        		last = last.next

        	last.next = newNode
        	newNode.prev = last
        	newNode.next = self.head

    
    def printList(self):
    	tmp = self.head
    	if(self.head is None):
    		print("No list created")

    	while(tmp != self.head):
    		print(self.head.data,'->',end='')
    		tmp = tmp.next


list = CircularLinkedList()

list.push(10)
list.push(11)
list.push(12)
list.push(13)
list.push(14)
list.push(15)


list.printList()