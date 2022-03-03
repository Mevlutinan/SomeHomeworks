/**
 * Test class
 * @author Reha Inan
 */

/**
 * this class for keep information both of them in same array (Branch Employee and transformation personnel)
 * Brach have personnel array
 * Branch employees and transportation personels base class
 */
public class Personnel{
    protected String name;
    protected String surName;
    private int ID;

    Personnel(){};

    /**
     * personnel constructor
     * @param name personnel name
     * @param surName personnel surname
     * @param ID personnel ID
     */
    Personnel(String name,String surName,int ID){
        this.name=name;
        this.surName=surName;
        this.ID=ID;
    }

    /**
     * getting personnel name
     * @return name
     */
    public String getName() { return name; }

    /**
     * getting personnel surname
     * @return surname
     */
    public String getSurName() { return surName; }

    /**
     * setting personnel name
     * @param name personnel name
     */
    public void setName(String name) { this.name = name; }

    /**
     * setting personnel surname
     * @param surName
     */
    public void setSurName(String surName) { this.surName = surName; }

    /**
     * getting personnel ID
     * @return personnel ID
     */
    public int getID() { return this.ID; }

    /**
     * setting personnel ID
     * @param ID Personnel ID
     */
    public void setID(int ID) { this.ID = ID; }
}
