/**
 * Test class
 * @author Reha Inan
 */
public class TransportationPersonnel extends Personnel{
 /*   private String name;
    private String surName;
    private int ID;*/
    private Branch myBranch;

    /**
     * getting Transportation's branch
     * @return Transportation's branch
     */
    public Branch getMyBranch() {
        return this.myBranch;
    }

    /**
     * setting Transportation's branch
     * @param myBranch Transportation's branch
     */
    public void setMyBranch(Branch myBranch) {
        this.myBranch = myBranch;
    }

    /**
     * transportation presonel constructor
     * @param PName his/her name
     * @param PSurName his/her surname
     * @param ID his/her ID
     */
    public TransportationPersonnel(String PName,String PSurName,int ID){
        super(PName,PSurName,ID);
    }
    /**
     * Transportation Personnel update the package info
     * @param ppackage Package object
     * */
    public void packageUpdateTo_Delivered(Package ppackage){
        ArrayFunctions.findObjectlist(Branch.getPackages(),myBranch.getPackageCount(),ppackage).delivered();
    }
    /**
     *Print Transportation Personnel infos
     * */
    public void printt(){
        System.out.println(super.name+" "+super.surName);
    }
}
