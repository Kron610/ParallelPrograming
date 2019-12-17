import java.awt.Color;
public class Claster
{
    private static double size = 10;
    private Stack<Point2D> points;
    private Color color;
    Claster(String claster, Color color)
    {
        In in = new In(claster);
        points = new Stack<>();
        while (!in.isEmpty())
        {
            double x = in.readDouble();
            double y = in.readDouble();
            Point2D p = new Point2D(x, y);
            points.push(p);
        }
        this.color = color;
    }

    public void draw()
    {
        StdDraw.setXscale(0, size);
        StdDraw.setYscale(0, size);
        StdDraw.setPenRadius(0.02);
        StdDraw.setPenColor(this.color);
        for (Point2D point : points)
        {
            StdDraw.point(point.x(), point.y());
        }
    }
}
