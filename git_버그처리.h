
__Git으로 버그 찾기
$git reflog : HEAD가 변경된 이력(내용, 커밋ID, ..)를 보여준다.
//local에 저장되어 있으며
//reset --hard를 하여 특정 커밋(들)이 사라졌어도 local에서 작업한 내용이거나 
//remote에서 받아서 한번 이라도 들여다 봤다면 여기에 남아있다.(즉 복원 가능, 이력 삭제 불가능)

$git rebase
	> 

$git diff [커밋ID_앞4자리] [커밋ID_앞4자리]
$git diff [커밋ID_앞4자리] [커밋ID_앞4자리] [file]

$git blame -L line, line [file] :
	//"https://git-scm.com/book/ko/v2/Git-%EB%8F%84%EA%B5%AC-Git%EC%9C%BC%EB%A1%9C-%EB%B2%84%EA%B7%B8-%EC%B0%BE%EA%B8%B0"



$git hash-object -w [file] :
$git cat-file -p "hash" :
$echo -n "char..string" | git hash-object --stdin -w :
	//https://kotlinworld.tistory.com/301



dquote> 탈출하기는 바로 "CTRL + G"
