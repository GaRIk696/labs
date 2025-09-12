program lab_8;
const
    MAX_N = 10;
type
    TArray = array[1..MAX_N] of Integer;
var
    N: Integer;
    B, C, D: TArray;
    i, j: Integer;
    X, Y, Z: Real;

function CalculateX(N: Integer; B: TArray): Real;
var
    i, j: Integer;
    sum: Real;
begin
    sum := 1;
    
    for i := 1 to N do
    begin
        for j := 1 to i do
        begin
            sum := sum * (B[j] * B[j]);
        end;
    end;
    CalculateX := sum;
end;
function CalculateY(N: Integer; C: TArray): Real;
var
    i, j: Integer;
    product: Real;
begin
    product := 1;
    
    for i := 1 to N do
    begin
        for j := 1 to i do
        begin
            product := product * C[j];
        end;
    end;
    CalculateY := product;
end;
function CalculateZ(N: Integer; D: TArray): Real;
var
    i, j: Integer;
    product: Real;
begin
    product := 1;
    
    for i := 1 to N do
    begin
        for j := 1 to i do
        begin
            product := product * sqrt(D[j]);
        end;
    end;
    CalculateZ := product;
end;
begin
    writeln('Введите значение N (не более ', MAX_N, '): ');
    readln(N);

    writeln('Введите элементы массива B:');
    for i := 1 to N do
    begin
        readln(B[i]);
    end;

    writeln('Введите элементы массива C:');
    for i := 1 to N do
    begin
        readln(C[i]);
    end;

    writeln('Введите элементы массива D:');
    for i := 1 to N do
    begin
        readln(D[i]);
    end;

    X := CalculateX(N, B);
    Y := CalculateY(N, C);
    Z := CalculateZ(N, D);

    writeln('Значение X: ', X:0:2);
    writeln('Значение Y: ', Y:0:2);
    writeln('Значение Z: ', Z:0:2);
end.