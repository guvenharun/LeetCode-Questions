class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def deleteDuplicates(self, head):
        current = head
        
        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        return head
                
                           
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
    head = insert(head, 1)
    head = insert(head, 1)
    head = insert(head, 2)
    head = insert(head, 3)
    head = insert(head, 3)

    printList(head)

    solution = Solution()
    head = solution.deleteDuplicates(head)

    printList(head)