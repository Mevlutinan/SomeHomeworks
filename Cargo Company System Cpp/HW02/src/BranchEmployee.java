/**
 * Test class
 * @author Reha Inan
 */
public class BranchEmployee extends Personnel{

    private Branch myBranch;

    /**
     * Getters and setters
     * @param branch his/her branch object
     */

    public void setMyBranch(Branch branch){
        this.myBranch=branch;
    }
    public Branch getMyBranch() {
        return this.myBranch;
    }

    /**
     * brach employee constructor
     * @param PName his/her name
     * @param PSurName his/her surname
     * @param ID /hes/her ID
     */
    public BranchEmployee(String PName,String PSurName,int ID){
        super(PName,PSurName,ID);
  }
    /**
     * Uptading Package information to on the way
     * @param ppackage package object
     * */

    public void packageUpdateTo_OnTheWay(Package ppackage){

        ArrayFunctions.findObjectlist(myBranch.getPackages(),myBranch.getPackageCount(),ppackage).onTheWay();
    }

    /**
     * Package informaiton update to in the branch
     * @param ppackage
     */
    public void packageUpdateTo_InBranch(Package ppackage){

        ArrayFunctions.findObjectlist(myBranch.getPackages(),myBranch.getPackageCount(),ppackage).inBranch();
    }

    /**
     * Changeing Package informations
     * @param package1 deleting package
     * @param package2 new package instade of old one
     */
    public void setPackageInformation(Package package1,Package package2 ){
        ArrayFunctions.findObjectlist(myBranch.getPackages(),myBranch.getPackageCount(),package1).setSenderCustomer(package2.getSenderCustomer());
        ArrayFunctions.findObjectlist(myBranch.getPackages(),myBranch.getPackageCount(),package1).setReceiverCustomer(package2.getReceiverClient());
        ArrayFunctions.findObjectlist(myBranch.getPackages(),myBranch.getPackageCount(),package1).setTrackingnumber(package2.getTrackingnumber());
    }

    /**
     * Printing branch Emplooyees
     */
    public void printBrancEmployee(){
        System.out.println(this.name+" "+this.surName);

    }
}
