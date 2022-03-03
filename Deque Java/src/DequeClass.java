import java.util.AbstractCollection;
import java.util.Collection;
import java.util.Deque;
import java.util.Iterator;
/**
 * @author Mevlut Reha İnan 151044045
 */


/**
 * Node class
 */
class Node {

    Object data;

    Node next;
    Node prev;
    /**
     * Getter for next
     * @return this.next
     */
    public Node getnext() {
        //if(this.next ==null){System.out.println(".next is NULL!!");return null;}
        return this.next;
    }
    /**
     * Getprev
     * @return this.prev
     */
    public Node getprev() {
        //if(this.prev ==null){System.out.println(".prev is NULL!!");return null;}
        return this.prev;
    }
    /**
     * Getter for data
     * @return this.data
     */
    public Object getdata() {
        //if(this.data ==null){System.out.println(".data is NULL!!");return null;}
        return this.data;
    }
    /**
     * Setter for data
     * @param Pdata New data
     */
    public void setdata(Object Pdata) {
        //if(Pdata ==null){System.out.println("newdata is NULL!!");return;}
        this.data = Pdata;
    }
    /**
     * Default Constructor
     */
    Node() {
        data = next = prev = null;
    }
}
/**
 * Deque Class
 * Extend AbstractCollection class
 * Implements Deque class
 */
public class DequeClass extends AbstractCollection<Object> implements Deque<Object> {


    Node head;
    Node currentnode;
    Node tail;
    Node removedhead;
    Node removedtail;
    int removedsize=0;
    int size=0;
    /**
     * Default Constructor for Deque Class
     */
    DequeClass() {
        head = tail = null;
        removedhead = removedtail = null;
    }

    /**
     * Is deque empty or not
     * @return true if is empty otherwise false
     */
    @Override
    public boolean isEmpty() {
        return head == null;
    }
    /**
     * Convert deque to array[50]
     * @return Array
     */
    @Override
    public Object[] toArray() {
        Object[] list=new Object[50];
        Node temp=head;
        int i=0;
        while(temp!=null){
            list[i]=temp.getdata();
            temp=temp.getnext();
            i++;
        }
        return list;
    }
    /**
     * Is deque contains all collection member
     * @return id contains return true otherwise false
     */
    @Override
    public boolean containsAll(Collection<?> c) {
        int count=0;
        Node temp=head;
        while(temp!=null){
            if(c.contains(temp.getdata())){
                count++;
                if(count==c.size()){System.out.println("CONTAINS ALL");return true;}
            }
            temp=temp.getnext();
        }
        System.out.println("NOT CONTAINSALL");
        return false;
    }

    /**
     * Remove all collections datas to deque and add them to removed deque
     * @param c deleted datas' collection
     * @return  If deleted all return true otherwise false
     */
    @Override
    public boolean removeAll(Collection<?> c) {

        if(containsAll(c)){

            for (Object object : c) {
                if(object==null)return true;
                removeFirstOccurrence( ((Node) object).getdata() );
            }
        }else return false;
        return true;
    }

    /**
     * Shrink deque to collection
     * @param c Collection to shrinked
     * @return true always
     */
    @Override
    public boolean retainAll(Collection<?> c) {
        Node temp=head;

        while(temp!=null){
            if(!c.contains(temp.getdata())){
                removeFirstOccurrence(temp.getdata());
            }
            temp=temp.getnext();
        }

        return true;
    }

    /**
     * delete all nodes and add them to removednodes
     */
    @Override
    public void clear() {
        if(containsAll(this)){

            for (Object object : this) {
                if(object==null)return ;
                removeFirstOccurrence( ((Node) object).getdata() );
            }
        }
    }

    /**
     * Removeddeque name is trash and this function pop the removed node
     * @return Node to trash
     */
    private Node getLastFromTrash() {
        Node temp=removedtail;
        if(removedtail==null || removedsize<=0){System.out.println("getLastFromTrash: list is empty");return null;}
        if(removedsize==1){
            Node returnedNode = removedhead;
            removedhead=removedtail=null;
            removedsize--;
            return returnedNode;

        }
        if(removedsize==2){
            Node tmepo=removedtail;
            removedtail=removedhead;
            removedsize--;
            removedtail.prev=null;
            removedhead.next=null;
            tmepo.prev=tmepo.next=null;
            return tmepo;
        }

        removedtail=removedtail.prev;
        removedtail.next=null;
        removedsize--;

        return temp;
    }

    /**
     * Adding node to trash from deleting deque' nodes
     * @param newone save the node
     */
    private void addNodetotrash(Node newone){//to last as stack

        newone.next=newone.prev=null;
        if(removedhead==null && removedtail==null){
            if(removedsize<0){System.err.println("!!!!!!!!!!!!head==null");}
            else{
                newone.setdata(-10);
                removedhead=newone;
                removedtail=newone;
                removedsize++;
            }

        }else if(removedsize==1){
            newone.setdata(-11);
            removedhead.next=newone;
            newone.prev=removedhead;
            removedtail=newone;
            removedsize++;
        }
        else if(removedsize>=2){
            newone.setdata(-12);
            newone.prev=removedtail;
            removedtail.next=newone;
            removedtail=newone;
            removedsize++;
        }


    }


    /**
     * Add node to deques head from removeddeque(trash) if possible(any available)
     * @param e Adding node
     */
    @Override
    public void addFirst(Object e) {
        if(head==null && tail==null){
            if(size<0){System.err.println("!!!!!!!!!!!!head==null");}
            else{
                if(removedsize<=0){
                    Node newone=new Node();
                    newone.setdata(e);
                    head=newone;
                    tail=newone;
                    size++;
                }else{
                    Node temp=getLastFromTrash();
                    temp.setdata(e);
                    temp.next=temp.prev=null;
                    head=temp;
                    tail=temp;
                    size++;
                }
            }
        }else if(size==1){
            if(removedsize<=0){
                Node newone=new Node();
                newone.setdata(e);
                newone.next=tail;
                tail.prev=newone;
                head=newone;
                size++;
            }else{
                Node temp=getLastFromTrash();
                temp.setdata(e);
                temp.next=temp.prev=null;
                temp.next=tail;
                tail.prev=temp;
                head=temp;
                size++;
            }
        }
        else if(size>=2){
            if(removedsize<=0){
                Node newone=new Node();
                newone.setdata(e);
                newone.next=head;
                head.prev=newone;
                head=newone;
                size++;
            }else{
                Node temp=getLastFromTrash();
                Node oldhead = head;
                temp.next=null;
                temp.prev=null;
                temp.setdata(e);
                head=temp;
                temp.next=oldhead;
                oldhead.prev=temp;
                size++;
            }
        }

    }

    /**
     * Add node to deque tail from trash(any available)
     * @param e Adding node
     */
    @Override
    public void addLast(Object e) {
        if(head==null && tail==null){
            if(size<0){System.err.println("!!!tail==null");}
            else{
                if(removedsize<=0){
                    Node newone=new Node();
                    newone.setdata(e);
                    head=newone;
                    tail=newone;
                    size++;
                }else{
                    Node temp=getLastFromTrash();
                    temp.setdata(e);
                    temp.next=temp.prev=null;
                    head=temp;
                    tail=temp;
                    size++;
                }
            }

        }else if(size==1){
            if(removedsize<=0){
                Node newone=new Node();
                newone.setdata(e);
                newone.prev=head;
                head.next=newone;
                tail=newone;
                size++;
            }else{

                Node temp=getLastFromTrash();
                temp.setdata(e);
                temp.prev=temp.next=null;
                temp.prev=head;
                head.next=temp;
                tail=temp;
                size++;
            }
        }
        else if(size>=2){
            if(removedsize<=0){
                Node newone=new Node();
                newone.setdata(e);
                newone.prev=tail;
                tail.next=newone;
                tail=newone;
                size++;
            }else{
                Node temp=getLastFromTrash();
                Node oldtail = tail;
                temp.next=null;
                temp.prev=null;
                temp.setdata(e);
                tail=temp;
                temp.prev=oldtail;
                oldtail.next=temp;
                size++;
            }
        }
    }

    /**
     * Same as addfirst
     * @param e Adding node
     * @return If node null false
     */
    @Override
    public boolean offerFirst(Object e) {
        addFirst(e);
        return e!=null;
    }

    /**
     * Same as addlast
     * @param e Adding node
     * @return If node is null false
     */
    @Override
    public boolean offerLast(Object e) {
        addLast(e);
        return e!=null;
    }

    /**
     * Same as Removefirstoccurrence
     * @return Head
     */
    @Override
    public Object removeFirst() {
        Node temp=head;
        removeFirstOccurrence(temp.getdata());
        return head;
    }

    /**
     * Same as Removelastoccurrence
     * @return tail
     */
    @Override
    public Object removeLast() {
        Node temp=tail;
        removeLastOccurrence(temp.getdata());
        return tail;
    }

    /**
     * Same as removeFirst
     * @return Heads copy
     */
    @Override
    public Object pollFirst() {
        Node temp=head;
        if(size==0)return null;
        removeFirst();
        return temp;
    }

    /**
     * Same as removelast
     * @return tail
     */
    @Override
    public Object pollLast() {
        Node temp=tail;
        if(size==0)return null;
        removeLast();
        return temp;
    }

    /**
     * same as Gethead
     * @return Head;
     */
    @Override
    public Object getFirst() {
        Node temp=head;
        return temp;
    }

    /**
     * Same as gettail
     * @return tail
     */
    @Override
    public Object getLast() {
        Node temp=tail;
        return temp;
    }

    /**
     * Same as getfirst
     * @return Head
     */
    @Override
    public Object peekFirst() {
        Node temp=head;

        if(head==null){System.out.println("Peek first:head is null!!!!!");return null;}
        return temp;
    }

    /**
     * Same as getlast
     * @return Tail
     */
    @Override
    public Object peekLast() {
        if(tail==null){System.out.println("Peek last:tail is null!!!!!");return null;}
        return tail;
    }

    /**
     * Remove first occurence starting from head
     * @param o Removing object
     * @return If deque have object true otherwise false
     */
    @Override
    public boolean removeFirstOccurrence(Object o) {
        Node temp=head;
        Node currentNode = null;
        Node currentNode_next = null;
        if(size==1){
            addNodetotrash(tail);
            tail=head=null;
            size--;
        }
        if(temp.getdata().equals(o)){
            if(head==null)return false;
            head=temp.next;
            head.prev=null;
            addNodetotrash(temp);
            size--;
            return true;
        }

        while(temp.getnext()!=null ){
            if(temp.getnext().getdata().equals(o)){
                if(temp.getnext().getnext()==null){
                    temp=tail;
                    tail = temp.prev;
                    tail.next = null;
                    addNodetotrash(temp);
                    size--;
                    return true;
                }
                currentNode = temp.next;
                temp.next = null;
                currentNode_next=currentNode.getnext();
                currentNode_next.prev=null;
                addNodetotrash(currentNode);
                currentNode_next.prev = temp;
                temp.next = currentNode_next;
                size--;
                return true;
            }
            temp=temp.getnext();
        }
        return false;
    }

    /**
     * Remove first occurence starting from tail
     * @param o Removing object
     * @return If deque have object true otherwise false
     */
    @Override
    public boolean removeLastOccurrence(Object o) {
        Node temp=tail;
        Node currentNode = null;
        Node currentNode_prev = null;
        if(size==1){
            addNodetotrash(tail);
            tail=head=null;
            size--;
        }
        if(temp.getdata().equals(o)){
            if(tail==null)return false;
            tail=temp.prev;
            tail.next=null;
            addNodetotrash(temp);
            size--;
            return true;
        }
        while(temp.getprev()!=null ){
            if(temp.getprev().getdata().equals(o)){
                if(temp.getprev().getprev()==null){
                    temp=head;
                    head = temp.next;
                    head.prev = null;
                    addNodetotrash(temp);
                    size--;
                    return true;
                }
                currentNode = temp.prev;
                temp.prev = null;
                currentNode_prev=currentNode.getprev();
                currentNode_prev.next=null;
                addNodetotrash(currentNode);
                currentNode_prev.next = temp;
                temp.prev = currentNode_prev;
                size--;
                return true;
            }
            temp=temp.getprev();
        }
        return false;
    }

    /**
     * Same as addlast
     * @param e Adding node
     * @return True
     */
    @Override
    public boolean add(Object e) {
        addLast(e);
        return true;
    }

    /**
     * Same as Offerfirst
     * @param e Adding node
     * @return True
     */
    @Override
    public boolean offer(Object e) {

        offerLast(e);
        return true;
    }

    /**
     * Same as removeFirst
     * @return head;
     */
    @Override
    public Object remove() {
        removeFirst();
        return head;
    }

    /**
     * Same as pollfirst
     * @return head
     */
    @Override
    public Object poll() {
        pollFirst();
        return head;
    }

    /**
     * Same as getfirst
     * @return head
     */
    @Override
    public Object element() {
        return getFirst();
    }

    /**
     * Same as peekfirst
     * @return head
     */
    @Override
    public Object peek() {
        return peekFirst();
    }

    /**
     * Adding collections item to deque
     * @param c Adding collection
     * @return True
     */
    @Override
    public boolean addAll(Collection<?> c) {
        for (Object object : c) {
            add(((Node)object).getdata());
        }
        return true;
    }

    /**
     * Same as addFirst
     * @param e Adding object
     */
    @Override
    public void push(Object e) {
        addFirst(e);
    }

    /**
     * Same as removefirst
     * @return Null
     */
    @Override
    public Object pop() {
        removeFirst();
        return null;
    }

    /**
     * Same as removefirsoccurance
     * @param o Removing node
     * @return True
     */
    @Override
    public boolean remove(Object o) {
        removeFirstOccurrence(o);
        return true;
    }

    /**
     * Is deque contains object
     * @param o Seraching onject
     * @return False
     */
    @Override
    public boolean contains(Object o) {
        Node temp=head;
        while (temp!=null) {
            if(temp.getdata().equals(o))return true;
            temp=temp.getnext();
        }
        return false;
    }

    /**
     * Size of deque
     * @return Size
     */
    @Override
    public int size() { return size;}

    /**
     * Head iterator
     * @return Listiterator
     */
    @Override
    public Iterator<Object> iterator() {
        return new ListIterator(head);
    }

    /**
     * Tail iterator
     * @return Listiterator
     */
    @Override
    public Iterator<Object> descendingIterator() {
        return new ListIteratorDescending(tail);
    }

    /**
     * Printing Deque starting head and tail
     */
    public void printfdeque(){
        Node temp=head;
        System.out.println("start to head:");
//        System.out.println("SİZE:"+size);
        while (temp!=null) {
            System.out.println(temp.getdata());
            temp=temp.getnext();
        }
        temp=tail;
        System.out.println("start to Tail");
//        System.out.println("SİZE:"+size);
        while (temp!=null) {
            System.out.println(temp.getdata());
            temp=temp.getprev();
        }
    }

    /**
     * Printing trashDeque starting head and tail
     */
    public void printftrashdeque(){
        Node temp=removedhead;
        System.out.println("start to head:");
//        System.out.println("SİZE:"+removedsize);
        while (temp!=null) {
            System.out.println(temp.getdata());
            temp=temp.getnext();
        }
        temp=removedtail;
        System.out.println("start to Tail");
//        System.out.println("SİZE:"+removedsize);
        while (temp!=null) {
            System.out.println(temp.getdata());
            temp=temp.getprev();
        }
    }
}

/**
 * Listiterator class
 */
class ListIterator implements Iterator<Object> {
    private Node current;

    /**
     * Constructor of Iterator
     * @param head Head
     */
    ListIterator(Node head){
        current=head;
    }

    /**
     * Hasnext
     * @return If has next true otherwise false
     */
    @Override
    public boolean hasNext() {
        return current!=null;
    }

    /**
     * Updating to next
     * @return Current next
     */
    @Override
    public Node next() {
        Node temp=current;
        current=current.next;
        return temp;
    }

}

/**
 * Descending List iterator
 */
class ListIteratorDescending implements Iterator<Object> {

    private Node current;

    /**
     * Constructor of descending iterator
     * @param tail
     */
    ListIteratorDescending(Node tail){
        current=tail;
    }

    /**
     * Is has next or not
     * @return If has prev true otherwise false
     */
    @Override
    public boolean hasNext() {
        return current!=null;
    }

    /**
     * Updating next
     * @return Current prev
     */
    @Override
    public Node next() {
        Node temp=current;
        current=current.prev;
        return temp;
    }

}