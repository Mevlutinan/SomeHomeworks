public class Driver {
    public static void main(String[] args) {
        KWHeap<Object> temp=new KWHeap<>();
        KWHeap<Object> temp0=new KWHeap<>();

        temp.insert(new Node<>(50));
        temp.insert(new Node<>(80));
        temp.insert(new Node<>(90));
        temp.insert(new Node<>(40));
        temp.insert(new Node<>(10));
        temp.insert(new Node<>(10));

        temp.printlist();
        System.out.println("After deleting some Nodes");
        temp.delete(0);
        temp.delete(4);

        temp.printlist();

        temp0.insert(new Node<>(55));
        temp0.insert(new Node<>(77));
        temp0.insert(new Node<>(99));
        temp0.insert(new Node<>(33));

        System.out.println("Merging this list:");
        temp0.printlist();

        temp.merge(temp0.getHeaplist());
        System.out.println("Merged");
        temp.printlist();

        System.out.println("Printing with iterator");

        while (temp.hasNext()){
            System.out.print(temp.next().getData()+"  ");
        }
        System.out.println();
        System.out.println("After set method");
        temp.set(new Node<>(100));
        temp.printlist();

    }
}
