import java.awt.Color;
import java.util.TreeSet;

public class BoundaryVisualizer
{
    public static void main(String[] args)
    {
        int i = Integer.parseInt(args[0]);
        String clasterName = "../../Data/clasterBoundaries_" + i + ".txt";
        In inBoundaries = new In(clasterName);
        int boundariesCount = inBoundaries.readInt();
        for (int j = 0; j < boundariesCount; j++)
        {
            TreeSet<Point2D> points = new TreeSet<>();
            int pointsCount = inBoundaries.readInt();
            for (int k = 0; k < pointsCount; k++)
            {
                double x, y;
                x = inBoundaries.readDouble();
                y = inBoundaries.readDouble();
                Point2D point = new Point2D(x, y);
                points.add(point);
            }
            Boundary boundary = new Boundary(points, new Color(StdRandom.uniform(256), StdRandom.uniform(256), StdRandom.uniform(256)));
            boundary.draw();
        }
    }
}
