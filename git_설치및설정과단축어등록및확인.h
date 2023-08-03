
__ git 설치(터미널에서)
$sudo apt-get update
$sudo apt-get upgrade
$sudo apt-get install git-all
	> 설정 파일 위치
	1. global(--global): /home/[Linux user name]/.gitconfig
	2. local(--local): [git init 폴더]/.git/config
	// git에서 설정이 적용되는 우선 순위: local >> global
	// local 항목이 먼저 적용 되고, local에 없는 항목이 global에 있다면 해당 항목(들) 자동 적용

__ git 설정
$git config --global user.name "Myself" // 이름(name) 필수 
$git config --global user.email "7baetae@hanmail.net" // 이메일(email) 필수

$git config --global core.autocrlf "true"
$git config --global core.editor "code" //"Visual Studio Code"로 편집이 되도록 
$git config --global core.editor "code --wait" //열린 파일이 닫힐 때까지 기다린다.
$git config --global core.pager cat

$git config --global diff.tool vscode
$git config --global difftool.cmd "code --wait --diff $LOCAL $REMOTE" //[difftool "vscode"]

$git config --global init.defaultBranch main //$git init 할 때 [master]가 아닌 [main] 브랜치가 기본 브랜치 이름으로 생성

__ git 단축어 등록
$git config --global alias.s status                     //git s
$git config --global alias.ss "status -s"               //git ss
$git config --global alias.d difftool                   //git d
$git config --global alias.ds "diff --staged"           //git ds
$git config --global alias.l log                        //git l(git log) | git -P l(git --no-pager log)
$git config --global alias.i init                       //git i
$git config --global alias.lo "log --pretty=oneline"    //git lo
$git config --global alias.lr "log --pretty=reference"  //git lr
//$git config --global alias.lg "log --pretty=online --graph"   //git lg
$git config --global alias.lg "log --pretty=reference --graph"  //git lg
$git config --global alias.b branch                     //git b
$git config --global alias.k checkout                   //git k
$git config --global alias.c commit                     //git c
$git config --global alias.cm "commit -m"               //git cm
$git config --global alias.m merge                      //git m
$git config --global alias.a add                        //git a
$git config --global alias.r reflog                     //git r

__ git 단축어 확인
$git config --global --list
$git config --local --list

$git config --global -e //편집기로 파일 열림
$git config --local -e
