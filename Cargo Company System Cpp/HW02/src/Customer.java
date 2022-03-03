/**
 * Test class
 * @author Reha Inan
 */
public class Customer {

    private String name;
    private String surName;
    private int ID;
    private Branch myBranch;
    public Customer(){};

    /**
     * setters  Customer Branch
     * @param branch Customer branch
     */
    public void setMyBranch(Branch branch){ this.myBranch=branch; }

    /**
     * /**
     * getters  Customer Branch
     * @return
     */
    public Branch getMyBranch() { return this.myBranch; }
    /**
     * Customer constructor
     * @param PName customer Name
     * @param PSurName customer Surname
     * @param Pbranch customer Branch
     */
    public Customer(String PName,String PSurName,Branch Pbranch){
        this.myBranch=Pbranch;
        this.name=PName;
        this.surName=PSurName;
    }

    /**
     * Printing Customer information
     */
    public void printt(){
        System.out.println(this.name+" "+this.surName);
    }
}
