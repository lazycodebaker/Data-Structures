
class Node:
	def __init__(self,data):
		self.data = data
		self.next = None

class List:
	def __init__(self):
		self.head = None

	def append(self,data):
		temp = self.head
		new_node = Node(data)

		if(temp == None):
			temp = new_node
			return

		while temp.next is not None:
			temp = temp.next

		temp.next = new_node

	def get_length(self):
		if(self.head==None):
			return
		else:
			counter=0

			while (self.head is not None):
				self.head=self.head.next
				counter+=1
			print(counter)

	def delete_at(self,data):
		last = self.head

		if(self.head == None):
			print("No list Created...")
			return	
		else:
			if(self.head.data == data):
				head = last.next
				del(head)
				return

			while ():
				pass



	def print(self):
		temp = self.head

		while (temp is not None):
			print(temp.data)
			temp = temp.next

list = List()
list.head = Node(0)

list.append(1)
list.append(2)
list.append(3)
list.append(4)

list.print()
list.get_length()