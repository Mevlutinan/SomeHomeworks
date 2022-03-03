import java.util.*;

public class KWHeap<E> implements Iterator<Node<E>> {

    private ArrayList<Node<E>> Heaplist=new ArrayList<>();
    private int count;
    private int currentindex=0;

    /**
     * Defoult Constructor
     */
    public KWHeap(){
        count=0;
    }

    /**
     * Getter for Heaplist
     * @return Heaplist
     */
    public ArrayList<Node<E>> getHeaplist() {
        return Heaplist;
    }

    /**
     * Parent index returns
     * @param i Child Index
     * @return Paretn Index
     */
    public int parent(int i){return (i-1)/2;}

    /**
     * Left index returning
     * @param i Parent index
     * @return Left child index
     */
    public int left(int i){return 2*i+1;}

    /**
     * Right index returning
     * @param i Parent Index
     * @return  Right child index
     */
    public int right(int i){return 2*i+2;}


    /**
     * inserting node to heaplist
     * @param temp Added item
     */
    public void insert(Node<E> temp){

        int newOneIndex;
        count++;
        newOneIndex=count-1;
        Heaplist.add(temp);
        if (Heaplist.size()>1) {
            while (Heaplist.get(parent(newOneIndex)).data > Heaplist.get(newOneIndex).data) {
                Collections.swap(Heaplist,newOneIndex,parent(newOneIndex));
                newOneIndex = parent(newOneIndex);
            }
        }
    }

    /**
     * Swapping parent to child for smaller child
     * @param index child index
     * @param temp  Added node
     */
    public void toRoot(int index,Node<E> temp){

        Heaplist.get(index).setData(temp.getData());
        while (index!=0 && Heaplist.get(parent(index)).getData() > Heaplist.get(index).getData()){
            Collections.swap(Heaplist,index,parent(index));
            index=parent(index);
        }

    }

    /**
     * Reconstructed heap
     * @param index Index for smallest to recursive call
     */
    public void setheap(int index){

        int left=left(index);
        int right=right(index);
        int smallest=index;
        //
        if (left<Heaplist.size() && Heaplist.get(left).getData() < Heaplist.get(index).getData()){
            smallest=left;
        }
        if (right<Heaplist.size() && Heaplist.get(right).getData() < Heaplist.get(smallest).getData()){
            smallest=right;
        }
        if (smallest!=index){
            Collections.swap(Heaplist,index,smallest);
            setheap(smallest);
        }

    }

    /**
     * Remove root
     */
    public void removeroot(){
        if(Heaplist.size()==1){
            Heaplist=null;
            count--;
        }
        assert Heaplist != null;
        Heaplist.set(0, Heaplist.get(count - 1));

        Heaplist.remove(count-1);
        count--;
        setheap(0);

    }

    /**
     * Want to deleting item move to root and deleting root
     * @param index Deleting item index
     */
    public void delete(int index){
        Node<E> temp=new Node<>(-1);
        toRoot(index,temp);
        removeroot();

    }

    /**
     * Merging two list
     * @param list Merging list
     */
    public void merge(ArrayList<Node<E>> list){
        int i=0;
        while (list.size()>i) {
            this.insert(list.get(i));
            i++;
        }
    }


    /**
     * List printer
     */
    public void printlist(){
        int i=0;
        while(Heaplist.size()>i){
            System.out.print(Heaplist.get(i).data+"  ");
            i++;
        }
        System.out.println();
    }

    /**
     * Next item null or not null
     * @return Null or not null
     */
    @Override
    public boolean hasNext() {
        if(currentindex+1==Heaplist.size())
            return false;
        else{
            return true;
        }
    }

    /**
     * Step up to next item
     * @return  Next item
     */
    @Override
    public Node<E> next() {
        currentindex++;
        return Heaplist.get(currentindex);
    }

    /**
     * Iterator set method
     * @param value Wanst to setying value
     * @return  Heaplist
     */
    public Node<E> set(Node<E> value){
        return Heaplist.set(currentindex,value);
    }
}
