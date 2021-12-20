# TCP-socket-programming
There are two clients, X and  Y, that  will  communicate  with  a  server. Clients  X  and  Y  will  each 
open a TCP socket to the server and send a message to the server. The message contains the 
name of the client followed by my first name(e.g., “Client X: Aneudys”).The  server accepts  connections  from  both  clients  and  after  it  has  received  messages  from both X and Yit  will print their messages and then send an acknowledgment back to both clients. 
The acknowledgment from the server contains the sequence in which the client messages 
were received(e.g., Clinet X: Aneudys received before Client Y: Aneudys)

For this particular output I call client Y before I call client X

<img width="455" alt="Screen Shot 2021-12-20 at 3 44 39 PM" src="https://user-images.githubusercontent.com/42681372/146830402-c17021c5-1732-414a-9d87-a6fb31d3f9d0.png">




For this particular output I call client X before client Y

<img width="454" alt="Screen Shot 2021-12-20 at 3 45 10 PM" src="https://user-images.githubusercontent.com/42681372/146830465-75d37e1d-ad09-4d6f-9527-8ec6fad4a904.png">
