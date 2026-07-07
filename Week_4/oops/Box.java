public class Box {

    protected double length;
    protected double breadth;

    public Box(double l, double b) {

        length = l;
        breadth = b;
    }

    public double area() {

        return length * breadth;
    }
}