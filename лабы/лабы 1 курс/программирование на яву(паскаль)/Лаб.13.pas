program lab_13;
uses graphabc;
var x, f1, f2, q: real; y1, y2, z, i: integer;
begin
write('sqrt(ln(x)), exp(ln(ln(x))/4);');
  line(40, 40,40, 420);
  line(40, 250, 600, 250);
  line(40, 40, 30, 50);
  line(40, 40, 50, 50);
  line(600, 250, 590, 240);
  line(600, 250, 590, 260);
  textout(30, 240, '0');
  textout(600, 250, 'x');
  textout(20, 40, 'y');
  x := 1;
  z := 40;
  i := 50;
  q := 0.5;
 while i < 200 do begin

    line(35, 250 - i, 45, 250 - i);
    line(35, 250 + i, 45, 250 + i);
    textout(5, 250 + i, -q);
    textout(5, 250 - i, q);
    q += 0.5;
    i += 50;
  end;
  i := 50;
  q := 1;
 while i < 550 do begin
    line(40 + i, 245, 40 + i, 255);
    textout(40 + i, 255, q);
    i += 120;
    q += 1;
  end;
 while (x < 5) do begin
 f1:=sqrt(ln(x));
 f2:=exp(ln(ln(x))/4);
 y1:=250-round(f1*100);
 y2:=250-round(f2*100);
 Setpixel(z, y1, clgreen);
 Setpixel(z, y2, clred);
 x += 0.0075;
 z += 1;
 end;
end.
