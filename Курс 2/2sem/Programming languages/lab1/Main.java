
class Main {
    public static void main(String[] args){
        int a=5,b=6,c=7;
        Triangle trig = new Triangle(a, b, c);
        double trigper = trig.CalcPerimeter();
        System.out.println(trigper);
        double trper = trig.CalcArea();
        System.out.println(trper);

        double r = 3;
        Circle cric = new Circle(r);
        double cricPer = cric.CalcPerimeter();
        double cricPl = cric.CalcArea();
        System.out.println(cricPer + " " + cricPl);
    }
}
