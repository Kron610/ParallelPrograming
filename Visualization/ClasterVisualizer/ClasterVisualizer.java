
import java.awt.*;

public class ClasterVisualizer
{
    public static void main( String[] args)                  // unit testing of the methods (optional)
    {
        In in = new In("../../Data/count.txt");
        int count = in.readInt();
        for (int i = 0; i < count; i++)
        {
            String clasterName = "../../Data/claster_" + i + ".txt";
            Claster claster = new Claster(clasterName, new Color(StdRandom.uniform(256), StdRandom.uniform(256), StdRandom.uniform(256)));
            claster.draw();
        }

    }
}
