import turtle

window = turtle.Screen()
window.bgcolor("red")

class Draw_grahic(object):
    def __init__(self, speed):
        self.speed = speed
          
    # draw a square
    def draw_square(self, angle_a, side=150):
        brad = turtle.Turtle()
        brad.shape("turtle")
        brad.color("yellow")
        brad.speed(self.speed) 
        
        brad.right(angle_a)        
        for i in range(4):
            brad.forward(side)
            brad.right(90)
        
    # draw a cirlce        
    def draw_circle(self):
        angel = turtle.Turtle()
        angel.shape("arrow")
        angel.color("yellow")
        angel.speed(self.speed)
        
        radius = input("Please input the long of circle:\n")
        angel.circle(int(radius))
    
    # draw a triangle
    def draw_triangle(self, angle_b, line = 150):
        angle = turtle.Turtle()
        angle.shape("circle")
        angle.color("black")
        angle.speed(self.speed)     
        
        #line  = input("Please input the long of trigangle:\n")
        angle.left(angle_b)
        for i in range(3):
            angle.forward(line)
            angle.left(120)

draw_one = Draw_grahic(0.1)
for i in range(25):
    angle_a = i * 15
    draw_one.draw_square(angle_a)
    
for i in range(25):
    angle_b = i * 15    
    draw_one.draw_triangle(angle_b)
    
window.exitonclick()