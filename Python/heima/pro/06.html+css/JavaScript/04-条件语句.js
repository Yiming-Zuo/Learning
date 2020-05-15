var iNum = 12, sNum = '12';
var sFruit = '苹果'
var x = 3, y = 6;
if(iNum == 12){
    alert('相等');
}else{
    alert('不相等');
}
if(sNum == 12){
    alert('相等');
}else{
    alert('不相等');
}
if(sNum === 12){
    alert('相等');
}else{
    alert('不相等');
}

if(sFruit == '苹果'){
    alert('是苹果');
}else if(sFruit == '梨'){
    alert('是梨');
}else{
    alert('爬爬爬');
}

if(x > 1 && y > 1){
    alert('都大于1');
}else{
    alert('至少有一个不大于1');
}
if(x < 4 || y < 4){
    alert('至少有一个小于4');
}else{
    alert('都不小于4');
}
if(!(x == y)){
    alert('不等于');
}else{
    alert('等于');
}