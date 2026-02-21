# ARP
 Address Resolution Protocol : IP주소를 알고 있을때 네트워크 물리 주소인 MAC 주소로 변환하는 프로토콜

# RARP
 Reverse Address Resolution Protocol : 호스트 주소의 물리주소를 알 때 IP주소로 알아내는데 사용하는 프로토콜

# IGMP 
 Internet Group Message Protocol : 인터넷에 연결된 컴퓨터가 멀티캐스트 그룹을 주위의 라우터에 알릴 수 있는 수단을 제공하는 프로토콜

# 학습목표
 네트워크 계층 주소 변환 프로토콜(ARP, RARP)을 설명할 수 있다.
 인터넷 그룹 메시지 프로토콜(IGMP)의 동작 과정을 설명할 수 있다.

# 학습내용
1	주소 변환 프로토콜
2	IGMP 프로토콜

주소 변환 프로토콜
	네트워크 계층에서 주소 변환 프로토콜은 ARP(Address Resolution Protocol), 역주소 변환 프로토콜은 RARP(Reverse Address Resolution Protocol)이다.
	ARP(Address Resolution Protocol)는 IP주소를 알고 있을때 물리주소인 MAC주소로 변환하는 프로토콜이다.
	ARP 요청은 브로드캐스트, 응답은 유니캐스트 방식이다.
	RARP(Reverse Address Resolution Protocol)는 호스트 주소의 물리주소를 알고 있을 때 IP주소를 알아내는데 사용하는 프로토콜이다.
IGMP 프로토콜
	IGMP는 임의의 호스트가 멀티캐스트 그룹에 가입하거나 탈퇴할 때 사용하는 프로토콜이다.
	질의 메시지는 주기적으로 라우터에 의해 자신에 접속되어 있는 모든 호스트로 그룹 내 멤버십에 대한 정보를 보고받기 위해 전송된다.