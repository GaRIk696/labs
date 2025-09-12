program lab_2;
  var x,y:real;
begin
  writeln('Введите координаты точки (x,y): ');
  readln(x,y);
  
  if (y<=(x+20)/3) and (y<=(x-28)/-3) and (y>=((7*x)-28)/-3) and (y>=((7*x)-28)/3) then
    if (x<=5) and (y>=5) then writeln('Точка принадлежит заданной фигуре')
    else writeln('Точка принадлежит заданной фигуре')
  else writeln('Точка не принадлежит заданной фигуре');
end.