public class Node<E> {

    protected int data;
    public Node (){}

    /**
     * Setter for data
     * @param data Setted data
     */
    public void setData(int data) {
        this.data = data;
    }

    /**
     * Getter data
     * @return Data
     */
    public int getData() {
        return data;
    }

    /**
     * Constructor for Node
     * @param data
     */
    public Node(int data){
        this.data=data;

    }

}
