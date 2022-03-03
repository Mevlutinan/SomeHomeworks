/**
 * Test class
 * @author Reha Inan
 */


public class CargoCompany {
    /**
     * Main
     * @param args command line parameter
     */
    public static void main(String[] args) {
/**
 * Creating administrator
 */
        Administrator reha =new Administrator("Reha","Inan");
        /**
         * Creating branches
          */
        Branch b1 = new Branch("Tuzla");
        Branch b2 = new Branch("Gebze");
        Branch b3 = new Branch("Atasehir");
        /**
         * Creating customers
         */
        Customer send=new Customer("fatma","gonderdi",b1);
        Customer reciever =new Customer("hatice","aldi",b1);

        Customer send1=new Customer("fatma1","gonderdi",b2);
        Customer reciever1 =new Customer("hatice1","aldi",b2);

        Customer send2=new Customer("fatma2","gonderdi",b3);
        Customer reciever2 =new Customer("hatice2","aldi",b3);
        /**
         * Creating packages
         */
        Package c1=new Package(send,reciever,10000);
        Package c2=new Package(send1,reciever1,10001);
        Package c3=new Package(send2,reciever2,10002);
        /**
         * Creating personnels
         */
        Personnel e1 = new TransportationPersonnel("Ali1","Yetis",1907);
        Personnel e2 = new BranchEmployee("Ayse2","Tedarik",1903);
        Personnel e3 = new TransportationPersonnel("Ali3","Yetis",1907);
        /**
         * Adding Branches
         */
        reha.addsomething(b1);
        reha.addsomething(b2);
        reha.addsomething(b3);
        reha.addsomething(b3);

        reha.printBranches();

        System.out.println("--------------");

        reha.removesomething(b2);
        reha.printBranches();

        /**
         * Administrator adding personnel
         */

        reha.findBranch(b1).addsomething(e1);
        reha.findBranch(b1).addsomething(e2);
        reha.findBranch(b1).addsomething(e3);

        b1.printEmployees();
        /**
         * Administrator removing personnel
         */
        reha.findBranch(b1).removesomething(e3);
        System.out.println("---------------");

        b1.printEmployees();

        System.out.println("---------------");
        /**
         * Branch Employee adding package to his/her branch
         */
        ((BranchEmployee)e2).getMyBranch().addPackage(c1);
        ((BranchEmployee)e2).getMyBranch().addPackage(c2);
        ((BranchEmployee)e2).getMyBranch().addPackage(c3);

        ((BranchEmployee)e2).getMyBranch().printPackages();

        System.out.println("---------------");
        /**
         * Branch Employee removing package to his/her branch
         */

        ((BranchEmployee)e2).getMyBranch().removePackage(c2);

        ((BranchEmployee)e2).getMyBranch().printPackages();

        System.out.println("----------------");

        c1.getSenderCustomer().printt();
        c1.getReceiverClient().printt();

        System.out.println("----------------++++");
        /**
         * Changeing reciver/sender information
         */
        c1.getReceiverClient().printt();
        ((BranchEmployee)e2).setPackageInformation(c1,c3);
        c1.getReceiverClient().printt();

        System.out.println("----------------+++++");
        /**
         * Branch Emplooye changeing package information
         */
        ((BranchEmployee)e2).packageUpdateTo_OnTheWay(c1);
        System.out.println(c1.getWhereAmI());

        System.out.println("----------------");
        /**
         * Tranportation personel updates pacgake information
         */
        ((TransportationPersonnel)e1).packageUpdateTo_Delivered(c1);
        System.out.println(c1.getWhereAmI());

        System.out.println("----------------");
        /**
         * Customer getting info about his package by tracking number
         */
        System.out.println(send.getMyBranch().getMyPackageinfo(10002).getWhereAmI());

    }
    public CargoCompany(){};
}