package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {

    public static void main(String[] args) {

        // (a) Veena object
        Veena v = new Veena();
        v.play();

        // (b) Saxophone object
        Saxophone s = new Saxophone();
        s.play();

        // (c) Interface reference
        Playable p;

        p = new Veena();
        p.play();

        p = new Saxophone();
        p.play();
    }
}