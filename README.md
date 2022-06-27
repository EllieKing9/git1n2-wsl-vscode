★ 이제 터미널에서 JMT 프로그래밍을 할 수 있따

<h6>
   
```
#define MAX 256

typedef enum boolean {
   FALSE= 0, FAIL= 0,
   TRUE= 1,
} BOOLEAN;

typedef enum _T_ENVIRONMENT_SET {
   OS= 1,
   CODE_EDITOR= 2,
   SERVICE= 3,
} T_ENVIRONMENT_SET;

typedef struct _T_STRING_SET {
   char os[MAX]= "Windows 10";
   char code_editor[MAX]= "Visual Studio Code";
   char service[MAX]= "WSL(Windows Subsystem for Linux";
} T_STRING_SET;

char environment(T_ENVIRONMENT_SET request, T_STRING_SET *str) {
   switch(request) {
      case OS:
         return str->os;
      case CODE_EDITOR:
         return str->code_editor;
      case SERVICE:
         return str->service;
      default: // ..
   }
}
```

```
void main(void) {
   T_STRING_SET str;
   int wsl_version= 1;
   
   __ Windows 10 에서 WSL 설치
   if (strcmp(environment(OS, &str), "Windows 10") == TRUE) {
      1. [Microsoft Store, 윈도우즈에서 store로 검색해서 실행] 에서 [linux]로 검색
      2. 원하는 리눅스 종류 및 버젼 선택하여 설치 //Ubuntu on Windows, 20.04 LTS
         __ 설치 불가인 경우ㅠ
         > [프로그램 및 기능] > [Windows 기능 켜기/끄기]에서 Linux용 Windows 하위 시스템 설정 가능
         > or 관리자 권한으로 PowerShell 실행하여 명령어로 설정 가능
         > Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
   } else {
      return FAIL;
   }
   
   __ WSL 버전 2로 업그레이드
   if (strcmp(environment(SERVICE, &str), "WSL(Windows Subsystem for Linux)") == TRUE) {
      > 윈도우즈 PowerShell에서 [wsl --list --verbose]로 버젼 확인
      if (wsl_version == 1) {
         3. WSL 버젼 2로 업그레이드
            > wsl_update_x64.msi 다운로드 및 설치 | 링크:
            https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi/			
            > 윈도우즈 PowerShell에서
            //> [wsl --set-default-version 2] 실행
            > [wsl --list --verbose]로 설치된 Linux name과 버젼을 확인 후,
            > 버젼 2가 배포되어 있지 않다면
            > [wsl --set-version name(linux) 2] 로 변환
      }
   }
   
   __ 폰트 설치
   1. 파워라인 적용된 폰트 다운로드 및 설치 | 링크:
   https://github.com/powerline/fonts/tree/master/DejaVuSansMono //DejaVu Sans Mono for Powerline
   https://github.com/powerline/fonts/tree/master/Meslo%20Dotted //Meslo LG S for Powerline
      > *.ttf 파일 다운로드하여 설치
   
   __ Visual Stduio Code 설치
   if (strcmp(environment(CODE_EDITOR, &str), "Visual Studio Code") == TRUE) {
      1. Code Editor 다운로드 및 설치 | 링크:
      https://code.visualstudio.com/
         > Visual Studio Code 실행 후,
         > extention 마켓에서 [wsl]를 검색하여 [WSL-remote] 설치
         > 위에서 설치한 Ubuntu(Windows Subsystem for Linux) 폴더에 접근하여 
           읽기, 수정, 저장 ... 이 가능
         > 파일 > 기본설정 > 설정 클릭 > 폰트 추가
         'SourceCodePro+Powerline+Awesome+Regular', 
         'DejaVu Sans Mono for Powerline', 'Meslo LG S for Powerline'
   
   __ Windows New Terminal 설치
   1. [Microsoft Store, 윈도우즈에서 store로 검색해서 실행] 에서 [windows terminal]로 검색 및 설치
      > Windows New terminal 실행 > 설정 > Json 파일 열기
      > "defaultProfile": "{Ubuntu guid값}" //실행시 Ubuntu가 기본으로 열리도록
      > 설정 > Ubuntu > 추가 설정 > 모양 클릭 > 글꼴 세팅(DejaVu Sans Mono for Powerline)
   
   __ oh-my-zsh 설치
   1. 우선 zsh 설치
      $sudo apt-get update
      $sudo apt-get install zsh
   2. oh-my-zsh 설치
      $sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
   3. 테마 변경
      $nano ~/.zshrc
         > ZSH_THEME="agnoster"
         > ZSH_THEME="amuse" 
         아래의 폴더에 많은 테마가 있음
         $cd ~/.oh-my-zsh/themes
   
   printf(" ★ 이제 터미널에서 MAC iTerm2와 같은 비쥬얼로 JMT 프로그래밍을 할 수 있따.\n");
}
```

