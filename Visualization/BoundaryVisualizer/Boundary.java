import java.awt.*;
import java.util.Iterator;
import java.util.TreeSet;

public class Boundary implements Iterable<Point2D>
{
    private Color color;

    private static double size = 10;

    private TreeSet<Point2D> points;

    public Iterator<Point2D> iterator()
    {
        return points.iterator();
    }

    public Boundary(TreeSet<Point2D> points, Color color)
    {
        this.points = points;
        this.color = color;
    }

    public void draw()
    {
        StdDraw.setPenColor(color);
        StdDraw.setPenRadius(0.05);
        StdDraw.setXscale(0, 10);
        StdDraw.setYscale(0, 10);
        for (Point2D point : points)
        {
            point.draw();
        }
    }
}
