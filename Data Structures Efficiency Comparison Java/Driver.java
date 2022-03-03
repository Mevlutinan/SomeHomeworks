import java.util.Random;
public class Driver {
    public static void main(String[] args) {

        BTree<Integer> BTree10k=new BTree<Integer>(2);
        BTree<Integer> BTree20k=new BTree<Integer>(2);
        BTree<Integer> BTree40k=new BTree<Integer>(2);
        BTree<Integer> BTree80k=new BTree<Integer>(2);



        Random r=new Random();

        int j=10;
        int averagetimesum=0;
        int averagetimesum1=0;
        int averagetimesum2=0;
        int averagetimesum3=0;

        int lenght = 10000;
        for (int i = 0; i < lenght; ++i) {
            BTree10k.add(r.nextInt(80000));
        }

        lenght = 20000;
        for (int i = 0; i < lenght; ++i) {
            BTree20k.add(r.nextInt(80000));
        }

        lenght = 40000;
        for (int i = 0; i < lenght; ++i) {
            BTree40k.add(r.nextInt(80000));
        }

        lenght = 80000;
        for (int i = 0; i < lenght; ++i) {
            BTree80k.add(r.nextInt(80000));
        }



        for (int k=0;k<j;k++) {

            long start = System.nanoTime();
            for (int y = 0; y < 100; y++) {
                BTree10k.add(r.nextInt(80000));
            }
            long end = System.nanoTime();
            long elapsedTime = end - start;
            //System.out.println("BTS 10k add " + elapsedTime);
            averagetimesum += elapsedTime;



            long start1 = System.nanoTime();
            for (int y = 0; y < 100; y++) {
                BTree20k.add(r.nextInt(80000));
            }
            long end1 = System.nanoTime();
            long elapsedTime1 = end1 - start1;
            //System.out.println("BTS 20k add " + elapsedTime1);
            averagetimesum1 += elapsedTime1;



            long start2 = System.nanoTime();
            for (int y = 0; y < 100; y++) {
                BTree40k.add(r.nextInt(80000));
            }
            long end2 = System.nanoTime();
            long elapsedTime2 = end2 - start2;
            //System.out.println("BTS 40k add " + elapsedTime2);
            averagetimesum2 += elapsedTime2;



            long start3 = System.nanoTime();
            for (int y = 0; y < 100; y++) {
                BTree80k.add(r.nextInt(80000));
            }
            long end3 = System.nanoTime();
            long elapsedTime3 = end3 - start3;
            //System.out.println("BTS 80k add " + elapsedTime3);
            averagetimesum3 += elapsedTime3;
        }

        System.out.println("B-Tree: 10 time, average 100 item insert to 10k tree nanosec "+averagetimesum/ 1000 / j);
        System.out.println("B-Tree: 10 time, average 100 item insert to 20k tree nanosec "+averagetimesum1/ 1000 / j);
        System.out.println("B-Tree: 10 time, average 100 item insert to 40k tree nanosec "+averagetimesum2/ 1000 / j);
        System.out.println("B-Tree: 10 time, average 100 item insert to 80k tree nanosec "+averagetimesum3/ 1000 / j);
    }
}