abstract class Figure
{
	abstract double CalcArea();
	abstract double CalcPerimeter();
}

class Circle extends Figure
{
	private double r;

	public double CalcArea(){
		return Math.PI * r * r;
	}
	public double CalcPerimeter(){
		return 2 * Math.PI * r;
	}
	public double GetRadius(){
		return r;
	}

	public Circle(double r){
		this.r = r;
	}
}

class Triangle extends Figure
{
	private double a;
	private double b;
	private double c;

	public double CalcArea(){
		double p = CalcPerimeter() / 2;
		return Math.sqrt(p * (p - a) * (p - b) * (p - c));
	}
	public double CalcPerimeter(){
		return a + b + c;
	}

	public Triangle(double a, double b, double c){
		if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
		{
			this.a = a;
			this.b = b;
			this.c = c;
		}
		//else throw Exception(1, "Error creating triangle");
	}
}

class Ring extends Figure
{
	private double r;
	private double R;

	public double CalcArea(){
		return Math.PI * R * R - Math.PI * r * r;
	}
	public double CalcPerimeter(){
		return 2 * Math.PI * r + 2 * Math.PI * R;
	}
	public double GetSmallRadius(){
		return r;
	}
	public double GetBigRadius(){
		return R;
	}

	public Ring(double r, double R){
		if (r > 0 && R > 0 && r != R)
		{
			if (r > R)
			{
				this.r = R;
				this.R = r;
			}
			else
			{
				this.r = r;
				this.R = R;
			}
		}
		//else throw Exception(1, "Error creating ring");
	}
}
