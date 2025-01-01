class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseList(self, head):
        current = head
        prev = None
        n = None
        while current:
            n = current.next
            current.next = prev
            prev = current
            current = n
        return prev 
    
def insert(head, val):
    if not head:
        return ListNode(val)
    current = head
    while current.next:
        current = current.next
    current.next = ListNode(val)
    return head

def printList(head):
    current = head
    while current:
        print(f"{current.val} -> ", end="")
        current = current.next
    print("NULL")

if __name__ == "__main__":
    head = None
    head = insert(head, 1)
    head = insert(head, 2)
    head = insert(head, 3)
    head = insert(head, 4)
    head = insert(head, 5)
    head = insert(head, 6)

    printList(head)

    solution = Solution()
    head = solution. reverseList(head)

    printList(head)