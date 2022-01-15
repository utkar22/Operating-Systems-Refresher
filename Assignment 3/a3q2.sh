add(){
    ans=0
    for i do
        ans=$(( $ans + $i ))
    done
    echo $ans
    exit
}
mul(){
    ans=1
    for i do
        ans=$(( $ans * $i ))
    done
    echo $ans
    exit
}
sub(){
    ans=$2*2
    for i do
        ans=$(( $ans - $i ))
    done
    echo $ans
    exit
}
div(){
    ans=$2
    ans=$(( $ans / $3 ))
    echo $ans
    exit
}
exp(){
    ans=$2
    ans=$(( $ans ** $3 ))
    echo $ans
    exit
}
input="$@"
set $input
if [[ $1 -eq 'add' ]]
then
    add $input
fi
if [[ $1 -eq 'mul' ]]
then
    mul $input
fi
if [[ $1 -eq 'sub' ]]
then
    sub $input
fi
if [[ $1 -eq 'div' ]]
then
    div $input
fi
if [[ $1 -eq 'exp' ]]
then
    exp $input
fi