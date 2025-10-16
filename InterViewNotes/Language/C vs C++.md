C vs C++
malloc, free와 new, delete의 차이
1. malloc vs new
malloc는 단순히 사용할 크기만큼의 메모리를 할당해 줄 뿐, 값에 대한 초기화는 이루어지지 않음(할당된 메모리에는 쓰레기 값이 들어가 있음)
할당과 동시에 초기화 하기 위해서는 realloc를 사용해야 한다.
또한 malloc은 void 포인터를 반환하여 타입 캐스팅이 추가적으로 필요하다.
new는 할당과 동시에 초기화가 가능하며, 클래스의 생성자를 호출시켜준다. 

2. free vs delete의
free는 할당된 메모리를 다시 힙 메모리에서 사용할 수 있게 되돌려준다.
delete는 free의 역할에 더해 클래스의 소멸자도 호출시켜준다.

3. 요약
malloc/free: “바이트 수만큼 공간을 빌리고 반납” — 초기화 X, 생성자/소멸자 X, 실패 시 NULL.
new/delete: “객체를 만들고 파괴” — 생성자/소멸자 O, 타입 안전 반환, 실패 시 std::bad_alloc 예외.