# Prepare environment

> Installer and auto-updates are coming soon!

## 1. Download Easypt interpreter

You can obtain latest interpreter executale [here](https://ci.appveyor.com/project/Antollo/easypt). 

- For Windows click `Visual Studio 2017` then `artifacts` then `artifacts.zip`.
- For Linux click `Ubuntu` then `artifacts` then `artifacts.zip`.

Unpack `artifacts.zip` and place easypt interpreter in a worthy place.

## 2. Add Easypt interpreter to PATH

- For Windows:

  - Open Control Panel.
  - Go to System and Security then System.
  - Click Advanced System Settings.
  - Click the Environment Variables button.
  - Select Path from the User variables section and click Edit
  - Click the New button and paste path to interpreter.
  - Click Ok.


- For Linux run command

  ```bash
  export PATH="$PATH:/path/to/interpreter"
  ```

## 3. Download Visual Studio Code

Skip this step if you already have VS Code installed.

## 4. Add Easypt extension to VS Code

## 5. When you create new project add following `tasks.json` to project's `.vscode` directory:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Run ",
            "type": "process",
            "windows": {
                "command": "easypt.exe"
            },
            "linux": {
                "command": "easypt"
            },
            "args": [
                "-file",
                "my_source_file.ez"
            ],
            "presentation": {
                "reveal": "always",
                "panel": "new"
            },
            "problemMatcher": [],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

Change `my_source_file.ez` to your source file name. Now you are able to run Easypt code with VS Code build task (`Ctrl+Shift+B`).

---

[Next lesson (Basics)](basics.md)

[Table of contents](tutorial.md)