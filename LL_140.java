// Solution:
// - Copy next pointer of each node to the random pointer
// - Now, sort the linked list based on random pointer
// - After sorting, random pointer of each node will point to next larger element
// - Time Complexity: O(nlogn) 
// - Space Complexity: O(1) as we're taking only constant variables

package linkedListRandomPointerSorted;

class Node {
  Node next;
  Node random;
  int data;
}

class LinkedList {

  public Node arbitraryPointToNextGreaterElement(Node head) { // refer from coding simplified utube channel
    if (head == null || head.next == null) {
      return head;
    }

    Node node = head;
    while (node != null) {
      node.random = node.next;
      node = node.next;
    }

    sortLinkedList(head);

    return head;
  }

  public Node sortLinkedList(Node node) {
    if (node == null || node.random == null) {
      return node;
    }

    Node middle = getMiddleNode(node);
    Node second = middle.random;
    middle.random = null;

    return mergeTwoList(sortLinkedList(node), sortLinkedList(second));
  }

  public Node getMiddleNode(Node node) {
    if (node == null || node.random == null) {
      return node;
    }

    Node slow, fast;
    slow = fast = node;

    while (fast.random != null && fast.random.random != null) {
      slow = slow.random;
      fast = fast.random.random;
    }

    return slow;
  }

  public Node mergeTwoList(Node first, Node second) {
    if (first == null && second == null) {
      return null;
    }

    Node tmp = new Node();
    Node finalList = tmp;
    while (first != null && second != null) {
      if (first.data < second.data) {
        tmp.random = first;
        first = first.random;
      } else {
        tmp.random = second;
        second = second.random;
      }

      tmp = tmp.random;
    }

    tmp.random = (first != null) ? first : second;

    return finalList.random;
  }

  public Node createNewNode(int i) {
    Node a = new Node();
    a.data = i;
    a.next = null;
    a.random = null;
    return a;
  }

}

public class LinkedListApp {

  public static void main(String[] args) {
    LinkedList a = new LinkedList();

    Node head = a.createNewNode(22);
    head.next = a.createNewNode(5);
    head.next.next = a.createNewNode(3);
    head.next.next.next = a.createNewNode(15);
    head.next.next.next.next = a.createNewNode(37);

    head = a.arbitraryPointToNextGreaterElement(head);

  }

}