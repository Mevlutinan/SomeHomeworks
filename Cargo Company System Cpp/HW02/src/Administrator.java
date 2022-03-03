import java.util.ArrayList;
import java.util.PrimitiveIterator;

/**
 * Test class
 * @author Reha Inan
 */
public class Administrator implements ManupulateArrayList<Branch>{

    public Administrator() {};

    private String Name;
    private String SurName;
    private int ID;
    private int branchCount;

    private ArrayList<Branch> bracnhesArrayList=new ArrayList<Branch>(100);

    /**
     * Administrator constructor
     * @param PName administrator name
     * @param PSurName administrator surname
     */
    public Administrator(String PName, String PSurName) {
        this.Name = PName;
        this.SurName = PSurName;
    }
    /**
     * Admin can remove branch but we need to find branch first
     * @param branch
     * @return
     */
    public Branch findBranch(Branch branch){
        return ArrayFunctions.findObjectlist(bracnhesArrayList,branchCount,branch);
    }
    /**
     * Overriden method adding branches
     * @param newBranch adding branches
     */
    @Override
    public void addsomething(Branch newBranch){
        branchCount = ArrayFunctions.addObjecttolist(bracnhesArrayList,branchCount,newBranch);
    }
    /**
     * Overriden method removing branches
     * @param newBranch removing branches
     */
    @Override
    public void removesomething(Branch newBranch){
        branchCount=ArrayFunctions.removeObjectlist(bracnhesArrayList,branchCount,newBranch);
    }
    /**
     * printing branches
     */
    public void printBranches() {

        for (int j = 0; j < branchCount; j++) {
            System.out.println(bracnhesArrayList.get(j).getName());
        }
        System.out.println("\n");
    }
}