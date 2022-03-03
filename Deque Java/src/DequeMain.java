public class DequeMain {

    public static void main(String[] args){

        DequeClass list=new DequeClass();
        DequeClass listtest=new DequeClass();
        DequeClass list11=new DequeClass();

        listtest.add(1);
        listtest.add(2);
        listtest.add(3);
        listtest.add(4);
        listtest.add(5);
        listtest.add(6);
        listtest.add(7);

        list11.push(33);
        list11.add(55);
        list11.add(66);
        list11.add(11);


        listtest.printfdeque();

        listtest.addAll(list11);

        listtest.printfdeque();


        System.out.println("list is empty?:"+list.isEmpty());

        list.addFirst(3);
        list.offerFirst(2);
        list.addFirst(1);
        list.addLast(3);
        list.addLast(4);
        list.offerLast(5);
        list.addLast(6);
        list.offerLast(7);
        list.add(8);

        list.printfdeque();

        list.pollFirst();
        list.removeFirstOccurrence(3);
        list.removeLastOccurrence(3);
        list.pollLast();
        list.removeFirst();
        list.removeLast();
        list.remove();
        list.pop();

        list.printfdeque();

        System.out.println("getfirst.data:"+((Node )list.getFirst()).getdata() );
        System.out.println("getlast.data:"+((Node )list.getLast()).getdata() );
        System.out.println("peekfirst.data:"+((Node )list.getFirst()).getdata() );
        System.out.println("peeklast.data:"+((Node )list.getLast()).getdata() );

    }
}
