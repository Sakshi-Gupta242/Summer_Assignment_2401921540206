public class Outer {

    void display() {
        System.out.println("Outer class display");
    }

    class Inner {

        void display() {
            System.out.println("Inner class display");
        }
    }

    public static void main(String args[]) {

        Outer o = new Outer();

        o.display();

        Outer.Inner i = o.new Inner();

        i.display();
    }
}