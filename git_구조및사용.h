
__ git 구조
=> untrack | tracked(unmodified | modified) | staged(index, cached) | local repository | ... | remote repository
=> 		working directory 	    | 	  staging area 	    |		repository	
	> add [file] : "staged" 상태로
	> commit : "staged"의 현 상태를 "local repository"에 하나의 버젼으로 남기고 "unmodified" 상태로
	> rm -cached [file]: "staging area" 에서 [file] 제거 및 [file]를 "untrack" 상태로 변경, "modified"에 같은 이름의 파일이 있으면 충돌 에러
	> HEAD : 어떠한 커밋 하나를 가르킴 | HEAD가 가르키는 커밋 내용 그대로 "working directory"가 구성되어 진다

__ git 사용

$git config --local user.name "Myself" // 이름(name) 필수 
$git config --local user.email "7baetae@hanmail.net" // 이메일(email) 필수

$git config --local core.autocrlf "true"
$git config --local core.editor "code" //"Visual Studio Code"로 편집이 되도록 
$git config --local core.editor "code --wait" //열린 파일이 닫힐 때까지 기다린다.
$git config --local core.pager cat

$git config --local diff.tool vscode
$git config --local difftool.vscode.cmd "code --wait --diff $LOCAL $REMOTE" //[difftool "vscode"]

//$git config --local init.defaultBranch main //$git init 할 때 [master]가 아닌 [main] 브랜치가 기본 브랜치 이름으로 생성

$git config --local --list
$git config --local -e
	
$git init 

$git add [file] 
$git add . : 변경사항이 있는 모든 파일
$git add * : "working directory" 에서 삭제된 파일은 "staging area"에서도 삭제

$git rm --cached [file] : "staging area" 에서 [file] 제거 및 [file]를 "untrack" 상태로 변경
$git rm [file] : "tracked" 에서 [file] 제거
$rm [file] : "untacked" 에서 [file] 제거
$rm -fr [folder]

$git reset : 최신 add 취소
$git reset [file] : 특정 [file] 최신 add 취소
$git reset --soft [커밋ID_앞4자리] : "working" 안바뀜 "staging" 안바뀜 "repository" HEAD -> [커밋ID_앞4자리] 이동
$git reset --mixed [커밋ID_앞4자리] : "working" 안바뀜 "staging" 바뀜 "repository" HEAD -> [커밋ID_앞4자리] 이동
$git reset --hard [커밋ID_앞4자리] : "working" 바뀜 "staging" 바뀜 "repository" HEAD -> [커밋ID_앞4자리] 이동 | 과거 커밋[커밋ID_앞4자리]의 모습으로
$git revert [커밋ID_앞4자리] : [커밋ID_앞4자리] 이후의 커밋(들)을 순차적으로 뒤로 돌리면서 하나씩 추가로 더해서 커밋해 줌 3
	> 로컬에서 아직 push를 하지 않았거나 개인적으로 쓰는 브랜치라면 reset를
	> 공동 작업 환경이면 revert를 사용한다.

$git restore <fine_name> : 특정 파일을 HEAD commit으로 복구
$git restore --source <commit_id><file_name> : 특정 파일을 특정 commit으로 복구
$git restore --staged <file_name> : staging area에 있는 특정 파일을 unstaging(untrack)
	
$git commit -m "message" -m "sub message"
//editor : 첫줄 "message" 한 줄 건너 뛰고 "sub message"
$git commit --amend -m "message2" : 최신 커밋에 대하여 "message2"로 수정해서 새롭게 커밋
$git commit --amend --no-edit : 누락된 파일 추가 (git add된 파일)
	
$git branch [name] : 새로운 [name] branch 생성
$git switch [name] : [name] 브랜치로 작업환경 변경(이동)
$git branch -d [name] : [name] 브랜치 삭제
$git branch -a : local 및 remote의 모든 브랜치 확인
$git branch -m [name] : 현재 브랜치의 이름을 [name]으로 변경

$git checkout [name] : [name] 브랜치로 작업환경 변경(이동)
$git checkout -b [name] : [name] 브랜치를 만들고 해당 [name] 브랜치로 작업환경 변경(이동)변경
$git switch -c [name] : [name] 브랜치를 만들고 해당 [name] 브랜치로 작업환경 변경(이동)변경
$git checkout [커밋ID_앞4자리] : 특정 커밋를 시작점으로 하는 새로운 브랜치를 만들고 싶을 때 HEAD를 잠시 detached HEAD 상태로 두고 작업을 한다
	> 이 detached Head 가 가리키는 상태 그대로 브랜치 생성(git checkout -b [name]) 후, 다시 checkout 해서 돌아가 보면 HEAD가 원래대로 최신을 가리키고 있음 

$git merge [name] : 현재 브랜치에 [name] 브랜치의 내용이 합쳐진다
	> fast-forward merge :
	> 3-way merge :
$git merge [name] -m [message] : 브랜치 병합시에 업데이트된 내용이 있다면 메세지를 넣어준다
$git merge --abort [name] : Conflict가 발생한 경우ㅠ 머지를 시도하기 이전으로 복귀

$git remote -v
$git remote remove origin
$git remote add origin [web_url] 
	> $git remote add origin "https://github.com/EllieKing9/winsock2.git"

$git push -u origin master
	> -u(--set-upstream) : tracking connection : origin에 있는 master 브랜치를 tracking 한다는 설정
		> 트래킹 설정 후 $git pull, $git push 작동
	> 옵션(-u) 설정이 안된 경우
		> $git push origin master(local):master(remote) 와 같이 매번 기재해야 함
		//> $git push origin master:stbae/20230817
	>> Username, Password ==> Username, Token 으로 변경 됨
		> github.com -> Settings -> Developer settings -> Personal access tokens -> Generate new token -> Generate token
		""
	>> --allow-unrelated-histories
/*		 
remote: Support for password authentication was removed on August 13, 2021. Please use a personal access token instead.
remote: Please see https://github.blog/2020-12-15-token-authentication-requirements-for-git-operations/ for more information.
fatal: Authentication failed for '...'
*/
$git pull : 
	> merge conflict 발생 하는 경우
		> 충돌이 난 파일 수정 한 후
		> $git add [file]
		> $git commit -m "message" -m "sub message"
		> $git push

$git fetch : 원격저장소(remote repository)의 최신 이력(내용)를 가져오지만 병합(merge)은 하지 않는다.
	> 브랜치 리스트에는 안 보이지만 FETCH_HEAD 이름으로 체크아웃 할 수 있따아
		> $git checkout FETCH_HEAD

	> $git add [file]	
	> $git commit -m [message]
	> $git fetch
	> $git diff (local)브랜치 (remote)FETCH_HEAD
	> $git diff (local)브랜치 (remote)FETCH_HEAD [file]
		> "차분 내용을 살펴 볼 수 있다."
			> 1. 코드를 추가한 개발자에게 충돌이 나는 부분을 수정하여 다시 올려달라고 요청한 후,
				> $git pull
			> 2. 충돌이 나는 부분을 내가 해결			
				> $git merge FETCH_HEAD
				> $git add [file]	
				> $git commit -m [message]
				> $git push

$git clone [git 주소] [folder] 

$git stash : 최근 커밋 이후로 "Working directory" 에서 작업하던 내용을 깃이 따로 보관하고 최근 커밋 상태로 만들어 둠
	브랜치를 옮겨서 보관된 내용을 가져다 사용 가능
	> $git stash list
		> stash@{0}: ... : 커밋ID_앞7자리 ...
		> stash@{1}: ... : 커밋ID_앞7자리 ...
	> $git stash apply : 가장 최근의 stash를 적용(stash@{0})
	> $git stash apply [name] : stash [name]를 적용 //예로 [name]은 stash@{0}과 같은 이름이다.
		> "stash 한 브랜치가 아닌 다른 브랜치에서도 적용이 가능"
	> $git stash apply --index : "staging area" 영역의 상태도 변경시켜 준다.
	> $git stash drop
	> $git stash drop [name]
		> $git stash pop : apply 대신에 pop를 사용하면 drop를 하지 않아도 된다. 
			> "pop : stash를 적용하고 나서 바로 스택에서 해당 stash를 제거"
$git stash --keep-index : "staging area"에 들어 있는 파일은 stash 하지 않는다.
$git stash --include-untracked : "untracked" 내용도 stash 한다.
$git stash branch [name] : stash 할 당시의 커밋을 Checkout 한 후 새로운 [name] 브랜치를 만들고 여기에 적용하고 stash를 삭제한다.

$git chery-pick [커밋ID_앞4자리] :
	> 

$touch .gitignore
$echo "*.log" > .gitignore


//Git bash에서 한글 파일명 깨지는 경우
$git config --global core.quotepath false
