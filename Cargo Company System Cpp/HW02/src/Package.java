/**
 * Test class
 * @author Reha Inan
 */
public class Package {


    private int trackingnumber;
    /**
     * Creating package custormer sender and receiver
     */
    private  Customer senderClient =new Customer("sender client name1","surname2",getMyBranch());
    private  Customer receiverClient =new Customer("reciever client name1","surname2",getMyBranch());
    /**
     * package' branch object
     */
    private Branch myBranch;
    /**
     * is package in branch or on the way informatıon
     */
    private String whereAmI="noOneKnows";

    /**
     * Setting Package's branch
     * @param branch Package's branch
     */
    public void setMyBranch(Branch branch){
        this.myBranch=branch;
    }

    /**
     * getting Package's branch
     * @return Package's branch
     */
    public Branch getMyBranch() {
        return this.myBranch;
    }

    /**
     * Printing where is the package
     * @return Where it is the Package
     */
    public String getWhereAmI() { return whereAmI; }

    /**
     * updating bracnh information
     */
    public void inBranch(){this.whereAmI="Branch";}

    /**
     * updating bracnh information to On The Way
     */
    public void onTheWay(){this.whereAmI="On The Way";}

    /**
     * updating bracnh information delivered
     */
    public void delivered(){ this.whereAmI="Delivered"; }

    /**
     * setting Package sender information
     * @param sender sender object
     */
    public void setSenderCustomer(Customer sender){ this.senderClient=sender; }

    /**
     * setting receiver customer information
     * @param receiver reciever object
     */
    public void setReceiverCustomer(Customer receiver){ this.receiverClient=receiver; }

    /**
     * getting sender customer information
     * @return sender customer object
     */
    public Customer getSenderCustomer(){ return this.senderClient; }

    /**
     * getting receiver customer information
     * @return receiver object
     */
    public Customer getReceiverClient() { return this.receiverClient; }

    /**
     * package costructor
     * @param sender sender object
     * @param receiver receiver object
     * @param trackingnumber package tracking number
     */
    public Package(Customer sender, Customer receiver, int trackingnumber){
        this.senderClient=sender;
        this.receiverClient=receiver;
        this.trackingnumber=trackingnumber;
    }

    /**
     * getting package tracking number
     * @return tracking number
     */
    public int getTrackingnumber() { return this.trackingnumber; }

    /**
     * setting tracking number
     * @param trackingnumber tracking number
     */
    public void setTrackingnumber(int trackingnumber) { this.trackingnumber = trackingnumber; }
}
