var abcdefg = null;
//var ss ="file:///D:/C++_source_code_Qt_VS/IT_QT/QT_C++_SourceCode/test_web/test.html";


//String.prototype.format是链接字符串
//prototype	允许您向对象添加属性和方法
String.prototype.format=function(){//传来了MSG,发送的信息
    if(arguments.length == 0) return this;
    //arguments数组 = 调用此函数的对象
    var obj = arguments[0];//arguments类数组对象, 是一个对应于传递给函数的参数的类数组对象。
    var s = this;//函数体this指向调用此函数的对象
    for(var key in obj) {//for(变量 in 对象) 循环变量数组
        //replace() 方法用于在字符串中用一些字符替换另一些字符，或替换一个与正则表达式匹配的子串。
        s = s.replace(new RegExp("\\{\\{" + key + "\\}\\}", "g"), obj[key]);
    }
    //this=s;
    return s;
}

        //连接的关键处
new QWebChannel(qt.webChannelTransport,
            function(channel){
                    abcdefg = channel.objects.abcdefg;
                     //window.foo = channel.objects.foo;
                    // context.contentChanged.connect(updateattribute);
                        }
            );



// 向qt发送消息
function sendMessage(msg)
{
    if(typeof abcdefg == 'undefined')
    {
        alert("abcdefg对象获取失败！");
    }
    else
    {
        abcdefg.onMsg(msg);
    }
}
// 控件控制函数
function onBtnSendMsg()
{
    var cmd = document.getElementById("待发送消息").value;
    sendMessage(cmd);   
}



// 接收qt发送的消息
function recvMessage(msg)
{
    alert("接收到Qt发送的消息：" + msg);
}



function appendHtml(msg){//尾部插入数据
    //$("#placeholder").append(abcdefg.msgRHtmlTmpl.format(msg));//这里调用的是通道中的msgRHtmlTmpl对象
    //$("#placeholder").append(abcdefg.msgRHtmlTmpl(msg));
    $("#placeholder").append(msg);
    window.scrollTo(0,document.body.scrollHeight); ;

};
