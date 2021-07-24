
''' Huffman coding is a lossless data compression algorithm .
The idea is to assign variable-length codes to input characters,
lengths of the assigned codes are based on the frequencies of corresponding characters.
The most frequent character gets the smallest code and the least frequent character gets the largest code.
The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) 
are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character.
This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream. 
The varibale length codes assgined are the prefix codes.


Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree. 

Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
Extract two nodes with the minimum frequency from the min heap.
 
Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.
Let us understand the algorithm with an example:

'''



class node:
	def __init__(self,freq,symbol,left=None,right=None):
		self.freq   = freq
		self.symbol = symbol
		self.left   = left
		self.right  = right

		self.huff   = ''


def printNodes(node,val=''):
	newVal = val + str(node.huff)

	if(node.left):
		printNodes(node.left,newVal)
	if(node.right):
		printNodes(node.right,newVal)

	if(not node.left and not node.right):
		print(f"{node.symbol} --> {newVal}")



chars = ['a','b','c','d','e','f']
freq  = [ 5,  9 ,12 , 13, 16 ,45]

nodes = []

for x in range(len(chars)):
	nodes.append(node(freq[x], chars[x]))

while len(nodes) > 1:
	nodes = sorted(nodes, key=lambda x: x.freq)
	left = nodes[0]
	right = nodes[1]
	
	left.huff = 0
	right.huff = 1

	newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)
	
	nodes.remove(left)
	nodes.remove(right)
	nodes.append(newNode)


printNodes(nodes[0])


'''
Time complexity: O(nlogn) where n is the number of unique characters.
 If there are n nodes, extractMin() is called 2*(n – 1) times. 
 extractMin() takes O(logn) time as it calles minHeapify().
  So, overall complexity is O(nlogn).
If the input array is sorted, there exists a linear time algorithm.
 We will soon be discussing in our next post.

Applications of Huffman Coding:
They are used for transmitting fax and text.
They are used by conventional compression formats like PKZIP, GZIP, etc.
'''