void setBuildStatus(String message, String state) {
  step([
      $class: "GitHubCommitStatusSetter",
      reposSource: [$class: "ManuallyEnteredRepositorySource", url: env.GIT_URL],
      contextSource: [$class: "ManuallyEnteredCommitContextSource", context: "ci/jenkins/build-status"],
      errorHandlers: [[$class: "ChangingBuildStatusErrorHandler", result: "UNSTABLE"]],
      statusResultSource: [ $class: "ConditionalStatusResultSource", results: [[$class: "AnyBuildResult", message: message, state: state]] ]
  ]);
}

def native = "native"
def board = "nucleo_g071rb"

pipeline {
    agent any

    stages {
        // stage('Build') {
        //     steps {
        //         setBuildStatus("Building...", "PENDING");
        //         echo 'Building...'
        //         // sh 'platformio run -e $board'  // compile only
        //     }
        // }
        stage('Build & Upload') {
            steps {
                setBuildStatus("Flashing firmware...", "PENDING");
                echo 'Flashing firmware....'
                sh 'platformio run -e $board -t upload -v'  // build and upload to device
            }
        }
        stage('Test') {
            steps {
                setBuildStatus("Testing...", "PENDING");
                echo 'Testing...'
                sh 'platformio test -e $native -v'   // native tests (on the pi)
                sh 'platformio test -e $board -v'    // tests on the board
            }
        }
        stage('Deploy') {
            steps {
                setBuildStatus("Deploying...", "PENDING");
                echo 'Deploying....'
            }
        }
    }
    post {
        success {
            setBuildStatus("Build succeeded", "SUCCESS");
        }
        failure {
            setBuildStatus("Build failed", "FAILURE");
        }
    }
}