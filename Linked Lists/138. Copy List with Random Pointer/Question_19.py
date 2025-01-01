class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        if not head:
            return None
        
        curr = head
        old_to_new = {}
        
        while curr:
            node = Node(x=curr.val)
            old_to_new[curr] = node
            curr = curr.next
        
        curr = head
        while curr:
            new_node = old_to_new[curr]
            new_node.next = old_to_new[curr.next] if curr.next else None
            new_node.random = old_to_new[curr.random] if curr.random else None
            curr = curr.next
        
        return old_to_new[head]

def insert(head, val):
    new_node = Node(val)
    if not head:
        return new_node
    current = head
    while current.next:
        current = current.next
    current.next = new_node
    return head

def createRandom(head, node, index):
    if index == -1: 
        node.random = None
    else:
        temp = head
        for i in range(index):
            if temp is not None:
                temp = temp.next
        node.random = temp

def printList(head):
    current = head
    while current:
        random_val = current.random.val if current.random else "NULL"
        print(f"Node({current.val}, Random -> {random_val})")
        current = current.next

if __name__ == "__main__":
    head = None
    head = insert(head, 7)
    head = insert(head, 13)
    head = insert(head, 11)
    head = insert(head, 10)
    head = insert(head, 1)
    

    createRandom(head, head, -1) 
    createRandom(head, head.next, 0)
    createRandom(head, head.next.next, 4) 
    createRandom(head, head.next.next.next, 2)  
    createRandom(head, head.next.next.next.next, 0) 
    
    print("Original list:")
    printList(head)

    solution = Solution()
    copied_head = solution.copyRandomList(head)
    
    print("\nCopied list:")
    printList(copied_head)
