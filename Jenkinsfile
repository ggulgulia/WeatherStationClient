pipeline {
    agent any
    triggers{ cron('H/15 * * * *') }
    stages {
        stage('Build') {
            steps {
                dir('sensor_interface') {
                    dir('build'){
                        sh 'cmake .. -DCMAKE_BUILD_TYPE=Debug -DCOVERAGE=ON'
                        sh 'make'
                    }
                }

            }
        }
        stage('Unit Test'){
            steps {
                dir('sensor_interface') {
                    dir('build'){
                        sh 'make coverage'
                    }
                }
            }

        }
    }

    post {
        always {
            publishHTML (
                            target: [
                                    allowMissing: false,
                                    alwaysLinkToLastBuild: false,
                                    keepAll: true,
                                    reportDir: 'sensor_interface/build/coverage',
                                    reportFiles: 'index.html',
                                    reportName: "Coverage Report"
                                ]
                        )

        }
    }
}