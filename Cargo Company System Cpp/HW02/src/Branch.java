import java.util.ArrayList;

/**
 * Test class
 * @author Reha Inan
 */
public class Branch implements ManupulateArrayList<Personnel> {

    private String name;
    private int personnelCount;

    private ArrayList<Personnel> brachesemployeelist=new ArrayList<Personnel>(100);


    private static   ArrayList<Package> packagearraylist=new ArrayList<Package>(1000);


    private int packageCount;

    /**
     *Getters and setters
     */
    public int getPackageCount() { return packageCount; }

    /**
     *getters and setter for branch
     */
    public String getName() { return this.name; }
    public void setName(String name) { this.name = name; }

    /**
     * Branch constructor
     * @param PName branch name
     */
    public Branch(String PName){ this.name=PName; }
    public static ArrayList<Package> getPackages() {
        return packagearraylist;
    }
    /**
     *Adding package to branch
     * @param newPackage new package
     * */
    public void addPackage(Package newPackage){
        newPackage.setMyBranch(this);
        packageCount=ArrayFunctions.addObjecttolist(packagearraylist,packageCount,newPackage);
    }
    /**
     *Printing package info for customer by tracknumber
     * @param trackNum package tracknumber
     * */
    public Package getMyPackageinfo(int trackNum){
        for (int i = 0; i <this.getPackageCount() ; i++) {
            if(trackNum==packagearraylist.get(i).getTrackingnumber()){
                return packagearraylist.get(i);
            }
        }
        return null;
    }
    /**
     *Removing package to branch
     * @param deletingPackage deleting Package
     * */
    public void removePackage(Package deletingPackage){
        packageCount=ArrayFunctions.removeObjectlist(packagearraylist,packageCount,deletingPackage);
    }

    /**
     * Overriden method adding personnel
     * @param newPersonnel adding personnel
     */
    @Override
    public void addsomething(Personnel newPersonnel){
        if (newPersonnel.getClass().equals(BranchEmployee.class)){
            ((BranchEmployee) newPersonnel).setMyBranch(this);
        }else if(newPersonnel.getClass().equals(TransportationPersonnel.class)){
            ((TransportationPersonnel) newPersonnel).setMyBranch(this);
        }
        personnelCount = ArrayFunctions.addObjecttolist(brachesemployeelist,personnelCount,newPersonnel);
    }

    /**
     * Overriden method removing personnel
     * @param newPersonnel removing personnel
     */
    @Override
    public void removesomething(Personnel newPersonnel){
        personnelCount=ArrayFunctions.removeObjectlist(brachesemployeelist,personnelCount,newPersonnel);
    }

    /**
     *Printing Employees
     * */
    public void printEmployees(){
        for (int j = 0; j <personnelCount ; j++) {
            System.out.println(brachesemployeelist.get(j).getName()+" "+brachesemployeelist.get(j).getSurName());
            System.out.println(brachesemployeelist.get(j).getClass().toString().substring(6)+"\n");
        }
    }
    /**
     *Printing Packages
     * */
    public void printPackages() {
        System.out.println("\n");
        for (int i = 0; i < packageCount; i++) {
            System.out.println(packagearraylist.get(i).getTrackingnumber()+" trackingnumber");
            //System.out.println(packagearray[i].getWhereAmI()+"  where am i\n");
            System.out.println(packagearraylist.get(i).getMyBranch().getName()+" branch"+"\n");
    }
}

}
